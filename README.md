# Minishell

![minishell](./gif/minishell.gif)

## Description
Minishell is a project carried out as part of the curriculum at Ecole 42. The goal is to create a command-line interpreter (shell) in the C language capable of understanding and executing certain basic commands.

## Features
- **Interactive Prompt:** Minishell displays an interactive prompt where the user can enter commands.
- **Built-in Commands:** The shell supports built-in commands such as `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Execve Commands:** with the function
  ```c
  int execve(const char *pathname, char *const _Nullable argv[], char *const _Nullable envp[]);
  ```
   you can execute any of the function that have a program in your computer located in your environment path.
- **Error Handling:** Minishell handles user errors informatively.
- **Redirections:** The shell supports standard input/output redirection (`>`, `<`, `>>`, `<<`).
- **Pipes:** Minishell allows the use of pipes for command chaining.
- **History of Command:** Minishell maintains a command history, allowing users to navigate and rerun previous commands.
- **Environment Variable:** The shell supports environment variables, allowing users to set and use variables in their commands.
- **Signal Handling:** Minishell implements signal handling to manage signals like Ctrl+C gracefully.

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
1. **Execution of Built-in Commands:** <br>
   ![image](https://github.com/cdurdetrouver/minishell/assets/76235778/3edab181-e196-459a-b8b9-fd8f78118340)

2. **Using Redirections:** <br>
   ![image](https://github.com/cdurdetrouver/minishell/assets/76235778/58f8d3a6-303b-4cdd-b73a-a720efc8e854)

3. **Using Pipes:** <br>
   ![image](https://github.com/cdurdetrouver/minishell/assets/76235778/7f46fbdb-f02d-4129-be54-50bc0b9d34de)

4. **Command not found:** <br>
   ![image](https://github.com/cdurdetrouver/minishell/assets/76235778/722d0f6f-ab04-4890-b4e4-d0f3ffe88460)

5. **Prompt is interactive** <br>
   ![image](https://github.com/cdurdetrouver/minishell/assets/76235778/23fd3c3a-dd94-40b1-b963-0de3cfafc75d)


## Authors
<table align="center">
  <tr>
    <td>
      <p align="center">
        <img src="https://cdn.intra.42.fr/users/d09dee629a391a7648155ed831d0aeb5/gbazart.jpg" alt="gbazart" width="100">
      </p>
      <p align="center"><a href="https://github.com/cdurdetrouver">gbazart</a></p>
    </td>
    <td>
      <p align="center">
        <img src="https://cdn.intra.42.fr/users/a5947886f8cad94d78e0286baeb8b7ef/hlamnaou.jpg" alt="hlamnaou" width="100">
      </p>
      <p align="center"><a href="https://github.com/ArCheRy154">hlamnaou</a></p>
    </td>
  </tr>
</table>
