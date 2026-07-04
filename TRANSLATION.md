# Vietnamese Translation

This fork translates **OI Wiki** into Vietnamese while keeping the upstream
MkDocs source layout intact.

## Current Scope

- `README.md`: translated and annotated for this fork.
- `docs/index.md`: translated landing page.
- `docs/intro/about.md`: translated project overview.
- `docs/contest/index.md`, `docs/lang/index.md`, `docs/basic/index.md`:
  translated section introductions.
- `docs/intro/what-oi-wiki-is-not.md`, `docs/intro/mirrors.md`,
  `docs/intro/thanks.md`: translated project policy and metadata pages.
- `docs/contest/problems.md`, `docs/contest/icpc.md`,
  `docs/contest/io.md`, `docs/contest/dictionary.md`,
  `docs/contest/common-tricks.md`: translated contest overview and technique
  pages.
- `docs/basic/complexity.md`, `docs/basic/amortized-analysis.md`,
  `docs/basic/enumerate.md`, `docs/basic/simulate.md`: translated basic
  algorithm foundation pages.
- `docs/basic/binary-lifting.md`, `docs/basic/construction.md`,
  `docs/basic/sort-intro.md`, `docs/basic/selection-sort.md`,
  `docs/basic/bubble-sort.md`, `docs/basic/insertion-sort.md`,
  `docs/basic/counting-sort.md`, `docs/basic/use-of-sort.md`: translated
  additional basic algorithm and sorting pages.
- `docs/contest/resources.md`, `docs/contest/roadmap.md`: translated learning
  resources and roadmap pages.
- `docs/intro/htc.md`, `docs/intro/faq.md`: translated contributor guide and
  FAQ, while preserving compatibility anchors for existing upstream links.
- Section introductions for search, dynamic programming, strings, mathematics,
  data structures, graph theory, computational geometry, and miscellaneous
  topics are translated.
- `mkdocs.yml`: Vietnamese project metadata and translated top-level
  navigation labels for translated sections and pages.

The rest of `docs/` is intentionally left in the upstream structure and should
be translated page by page.

## Translation Conventions

- "competitive programming" -> "lập trình thi đấu"; optionally add
  "(competitive programming)" near the first occurrence.
- "Olympiad in Informatics" -> "Olympic Tin học" or "Olympiad Tin học" based
  on context.
- "algorithm" -> "thuật toán".
- "data structure" -> "cấu trúc dữ liệu".
- "graph" -> "đồ thị".
- "dynamic programming" -> "quy hoạch động"; use "DP" after the first clear
  occurrence when the source uses DP heavily.
- "string" -> "xâu" in algorithmic contexts; use "chuỗi" only when it reads
  more naturally for programming-language discussion.
- "range query" -> "truy vấn đoạn".
- "segment tree" -> "cây phân đoạn (segment tree)" on first occurrence, then
  "cây phân đoạn".
- "binary search" -> "tìm kiếm nhị phân" or "chặt nhị phân" depending on
  context; prefer "tìm kiếm nhị phân" in headings and beginner pages.
- "sweep line" -> "đường quét (sweep line)" on first occurrence.
- Keep names of contests, online judges, libraries, programming languages,
  commands, file paths, and code identifiers unchanged unless the surrounding
  prose explicitly explains them.
- Preserve formulas, asymptotic notation, examples, admonitions, links,
  frontmatter keys, and MkDocs extension syntax.
- Use English in parentheses sparingly for terms readers are likely to search
  for in editorials or documentation.

## Workflow

1. Translate in place under the original file path so upstream changes remain
   easy to merge.
2. Keep each commit focused on a small group of related pages.
3. Run `mkdocs build -v` after structural changes or pages that touch
   frontmatter, navigation, admonitions, math, tabs, or custom HTML.
4. Do not mechanically translate code comments inside examples unless they are
   part of the explanation and the code remains valid.
5. Prefer concise Vietnamese prose over word-for-word Chinese or English
   sentence structure.

## Build

```bash
pip install uv
uv sync
./scripts/pre-build/install-theme.sh
uv run mkdocs build -v
```

The theme installation step downloads upstream theme resources, so it requires
network access.
