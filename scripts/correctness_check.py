# Check correctness of example code.
# input: related files to test (from get_files_to_test.py, read from $FILES_TO_TEST)
# output: None. Print to GitHub Action step summary.

import os
import subprocess

ACCEPTED = 1
ERROR = 0
SKIPPED = -1

def correctness_check(mainfile, auxfiles, examples, skiptest, summary):
    """
    Check correctness of one instance of example code.
    """

    print(f'::group::Test for {mainfile}...')
    # Whether to skip testing
    if skiptest:
        summary += f'## Skipped: {mainfile}\nTesting is skipped because {mainfile + ".skip_test"} exists.\n\n'
        print(f'::group::{mainfile}: test skipped')
        print(f'::endgroup::')
        return SKIPPED, summary
    
    # Check file existence
    for file in auxfile:
        if not os.path.exists(file):
            print(f'::endgroup::')
            print(f'::error file={file},title=file {file} not found::')
            summary += f'## File not found: {file}\nTesting for {mainfile} was aborted because {file} was not found.\n\n'
            return ERROR, summary
    for file in example:
        if not os.path.exists(file):
            print(f'::endgroup::')
            print(f'::error file={file},title=file {file} not found::')
            summary += f'## File not found: {file}\nTesting for {mainfile} was aborted because {file} was not found.\n\n'
            return ERROR, summary
        
    # Compile
    compile_command = f'g++ -std=c++17 {" ".join(auxfiles)} -o {mainfile.split(".")[0]}'
    print(compile_command, end=' ')

    result = subprocess.run(compile_command, shell=True)
    if result.returncode != 0:
        print(f'\n::endgroup::')
        print(f'::error file={mainfile},title=CE!::Compile Error! with error code {result.returncode}')
        summary += f'## CE: {mainfile}\n- Main file: `{mainfile}`\n- Auxiliary files: `{", ".join(auxfiles)}`\n- Test cases: `{", ".join(examples)}`\n- **Compile command**: {compile_command}\n- **Error code**: {result.returncode}\n\n'
        return ERROR, summary
    else:
        print('OK')
  
    # Special handling when no data points are provided
    if len(examples) == 0:
        print(f'\n::endgroup::')
        print(f"::warning file={mainfile},title=No data!::Can't find data to test. If you don't want this notice, create {mainfile.replace('.cpp', '.skip_test')}")
        summary += f'## No Data: {mainfile}\n- Main file: `{mainfile}`\n- Auxiliary files: `{", ".join(auxfiles)}`\n- Test cases: `{", ".join(examples)}`\n- Compile command: {compile_command}\nCompiled successfully, but further testing was not possible because data does not exist. **If testing is not desired, create {mainfile.replace(".cpp", ".skip_test")}**\n\n'
        return ACCEPTED, summary  

    # Test one by one
    executable = mainfile.split(".")[0]
    check_command = (f'diff -b -B {e.replace(".in", ".out")} {e.replace(".in", ".ans")}' for e in examples)
    for check, e in zip(check_command, examples):
        print(f'{executable} < {e} > {e.replace(".in", ".out")}', end=' ')
        with open(e, 'r') as fstdin:
            with open(e.replace(".in", ".out"), 'w') as fstdout:
                result = subprocess.run(executable, shell=True, stdin=fstdin, stdout=fstdout)
        if result.returncode != 0:
            print(f'\n::endgroup::')
            print(f'::error file={mainfile},title=RE!::Runtime Error! with error code: {result.returncode}')
            summary += f'## RE: {mainfile}\n- Main file: `{mainfile}`\n- Auxiliary files: `{", ".join(auxfiles)}`\n- Test cases: `{", ".join(examples)}`\n- **Failed test case**: {e}\n- **Error code**: {result.returncode}\n\n'
            return ERROR, summary
        else:
            print('OK')

        print(check, end=' ')
        result = subprocess.run(check, shell=True, stdout=subprocess.DEVNULL)
        if result.returncode != 0:
            print(f'\n::endgroup::')
            print(f'::error file={e},title=WA!::Wrong Answer on: {e}')
            summary += f'## WA: {mainfile}\n- Main file: `{mainfile}`\n- Auxiliary files: `{", ".join(auxfiles)}`\n- Test cases: `{", ".join(examples)}`\n- **Failed test case**: {e}\n\nExpected:\n```\n{open(e.replace(".in", ".ans")).read()}\n```\nActual output:\n```\n{open(e.replace(".in", ".out")).read()}\n```\n\n'
            return ERROR, summary
        else:
            print(f'Accepted!')

    summary += f'## AC: {mainfile} ({len(examples)} tests)\n- Main file: `{mainfile}`\n- Auxiliary files: `{", ".join(auxfiles)}`\n- Test cases: `{", ".join(examples)}`\n\n'
    print(f'::endgroup::')
    return ACCEPTED, summary

mainfiles, auxfiles, examples, skiptests = eval(os.environ.get("FILES_TO_TEST"))
summary = ''

cnt_ac, cnt_error, cnt_skip = 0, 0, 0
for mainfile, auxfile, example, skiptest in zip(mainfiles, auxfiles, examples, skiptests):
    correctness, summary = correctness_check(mainfile, auxfile, example, skiptest, summary)
    cnt_ac = cnt_ac + 1 if correctness == ACCEPTED else cnt_ac
    cnt_error = cnt_error + 1 if correctness == ERROR else cnt_error
    cnt_skip = cnt_skip + 1 if correctness == SKIPPED else cnt_skip

with open(os.environ.get('GITHUB_STEP_SUMMARY'), 'w') as f:
    f.write(f'# TOTAL {len(mainfiles)} TESTS, {cnt_ac} ACCEPTED, {cnt_skip} SKIPPED, {cnt_error} ERROR\n\n')
    f.write(summary)
    print(f'::group::TOTAL {len(mainfiles)} TESTS, {cnt_ac} ACCEPTED, {cnt_skip} SKIPPED, {cnt_error} ERROR\n::endgroup::')

if cnt_error:
    exit(1)
