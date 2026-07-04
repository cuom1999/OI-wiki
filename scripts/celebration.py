import requests
import json
import sys
from datetime import datetime
from math import log2

def nextCelebration(current):
    a = (current // 5000 + 1) * 5000
    b = 2 ** (int(log2(current)) + 1)
    return min(a, b)

headers = {
    "Authorization": f'token {sys.argv[1]}'
}

label = "Celebration / Chúc mừng"

query = f'''
query {{
    repository(owner: "OI-wiki", name: "OI-wiki") {{
        id
        stargazerCount
        label(name: "{label}") {{
            id
        }}
        issues(labels: "{label}", first: 100) {{
            nodes {{
                number
                title
                createdAt
                closed
                id
            }}
        }}
        defaultBranchRef {{
            target {{
                ... on Commit {{
                    history {{
                        totalCount
                    }}
                }}
            }}
        }}
    }}
}}
'''

res = requests.post('https://api.github.com/graphql', json.dumps({'query': query}), headers = headers).json()['data']['repository']

repositoryId = res['id']
stars = res['stargazerCount']
issues = res['issues']['nodes']
numbers = []

maxCelebration = 0
for issue in issues:
    numbers.append('#' + str(issue['number']))
    maxCelebration = max(maxCelebration, int(issue['title'].split(' ')[0]))
    timeDelta = (datetime.now() - datetime.fromisoformat(issue['createdAt'][0:-1]))
    if timeDelta.days >= 7 and not issue['closed']:
        mutation = f'''
mutation {{
    closeIssue(input: {{ issueId: "{issue['id']}"}}) {{
        issue {{
            number
            closed
        }}
    }}
}}
'''
        print(mutation)
        mut = requests.post('https://api.github.com/graphql', json.dumps({ 'query': mutation }), headers = headers)
        print(mut.text)

celebration = nextCelebration(maxCelebration)

if stars >= celebration - 1: # "will soon" reach
    mutation = f'''
mutation {{
  createIssue(input: {{
    repositoryId: "{repositoryId}",
    title: "{celebration} Stars Celebration",
    labelIds: ["{res['label']['id']}"],
    body: {json.dumps(f"""> To celebrate that our project's stars will soon reach {celebration}.
> This issue will be closed in one week.

Để chúc mừng dự án **OI Wiki** sắp đạt {celebration} sao, issue này được mở để mọi người cùng thư giãn một chút.

Mọi người đã vất vả duy trì dự án. Tôi vừa xem và thấy số commit cũng đã đạt {res['defaultBranchRef']['target']['history']['totalCount']}; trong issue này, mọi người cứ chia sẻ điều mình muốn nói (but please don't spam in this issue).

Chúc mọi người vui vẻ.

<!-- Nội dung dựa trên bản của @K-Guan -->

***

Cảm ơn mọi người rất nhiều vì đã ủng hộ trong suốt thời gian qua. Chúng ta hãy tiếp tục cố gắng.

Cuối cùng, chúc mọi người nhiều sức khỏe. Hẹn gặp lại khi đạt {nextCelebration(celebration)} sao.

cc {" ".join(numbers)}
""", ensure_ascii = False)}
  }}) {{
    issue {{
      number
    }}
  }}
}}
'''
    print(mutation)
    mut = requests.post('https://api.github.com/graphql', json.dumps({ 'query': mutation }), headers = headers)
    print(mut.text)
