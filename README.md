# pipex-42School
# 🧪 Pipex - 42 School Project

## 📖 Description

**Pipex** is a project from the [42 School](https://42.fr) curriculum that focuses on Unix-based process management and inter-process communication. 
It aims to recreate the behavior of shell pipelines using system calls like `fork()`, `pipe()`, `dup2()`, and `execve()`.

The program emulates the shell behavior of piping commands together with redirection, for example:

```bash
< infile cmd1 | cmd2 > outfile
```
### 🧪 Example

Suppose `file1` contains a list of files in the current directory.  
The following command:

```bash
./pipex file1 cat "grep .c" file2
Will simulate the shell behavior:

bash
Copia
Modifica
< file1 cat | grep .c > file2
✅ It will output to file2 only the lines that contain .c, for example:

txt
Copia
Modifica
ft_split.c
pipe_man.c
pipex.c
