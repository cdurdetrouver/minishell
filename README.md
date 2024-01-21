# Minishell

## Description
Minishell is a project carried out as part of the curriculum at Ecole 42. The goal is to create a command-line interpreter (shell) in the C language capable of understanding and executing certain basic commands.

## Features
- **Interactive Prompt:** Minishell displays an interactive prompt where the user can enter commands.
- **Built-in Commands:** The shell supports built-in commands such as `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Error Handling:** Minishell handles user errors informatively.
- **Redirections:** The shell supports standard input/output redirection (`>`, `<`, `>>`).
- **Pipes:** Minishell allows the use of pipes for command chaining.

## Compilation and Execution
To compile the project, use the `make` command:
```bash
make
```
To run the shell, use the following command:
```bash
./minishell
```
## Usage Examples
1. **Execution of Built-in Commands:**
   ```bash
   minishell$ echo "Hello, Minishell!"
   Hello, Minishell!
   ```
2. **Using Redirections:**
   ```bash
   🟢 cdurdetrouver@minishell: ../minishell$ cat file.txt > new_file.txt
   ```
3. **Using Pipes:**
<pre>
<span>🟢 </span><span style="color: red;">cdurdetrouver</span><span>@minishell</span><span>: </span><span>../minishell</span><span>$</span>
</pre>
## Authors
* cdurdetrouver
* hlamnaou
