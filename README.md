# Leetcode problems

## Useful Git commands

### Useful steps while creating a new Github project

`echo "# leetcode_problems" >> README.md`

`git init`\
`git add README.md`\
`git commit -m "first commit"`\
`git branch -M main`\
`git remote add origin https://github.com/karthikeyan2022/leetcode_problems.git`\
`git push -u origin main`

### Quick steps for commiting a small change in file

`git status`\
`git add filename`\
`git commit -m "any message"`\
`git push -u origin main`

### Command for cleaning untracked or ignored files

To show what files will be deleted, add `-n` option
`git clean -n -d`

Delete all files
`git clean -f`

To remove ignored files
`git clean -f -X`

To remove both ignored and non-ignored files
`git clean -f -x`

## Useful VS code shortcuts

Ctrl + 0 --> Focus on File explorer

Ctrl + PageUp/PageDown --> Traverse between open files

Ctrl + [num] --> Switch tab groups to particular [num] 1,2..

Ctrl + F4 --> close the open file where cursor is present.

Ctrl + Shift + ArrowUp --> Copy line up

Ctrl + Shift + ArrorDown --> Copy line down

Ctrl + Shift + K --> Delete current line

## Useful VIM shortcuts (edit & browsing)

dd --> delete the current line.

a --> move cursor to end of line for append

x --> delete a character present currently in cursor
