#include "parser.h"

void	init(t_head_struct *head_struct, char **envp)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	signal(15, SIG_IGN);
	head_struct->env = NULL;
	head_struct->list = NULL;
	head_struct->new_args = NULL;
	head_struct->copy_all = NULL;
	head_struct->envp = NULL;
	head_struct->last_spec = NULL;
	head_struct->flag_error = 0;
	all_envp(&(head_struct->env), envp);
	head_struct->bin = path_bin(&(head_struct->env));
	head_struct->saveinput = dup(0);
	head_struct->saveoutput = dup(1);
	head_struct->flag_redir = 0;
	g_error = 0;
}

void	gnl_and_parser(t_head_struct *head_struct, t_arg *arg)
{
	int res;

	if ((res = get_next_line(0, &g_str1)) > 0)
	{
		if (parser(g_str1, arg, head_struct) != -1)
		{
			free(g_str1);
			g_str1 = NULL;
		}
		else
		{
			if (g_str1)
				free(g_str1);
			g_str1 = NULL;
		}
	}
	if (res == 0)
	{
		ft_putstr_fd("\n", 1);
		exit(0);
	}
}

int		main(int argc, char **argv, char **envp)
{
	char			**arr;
	int				num;
	t_arg			arg;
	t_head_struct	head_struct;

	arr = argv;
	num = argc;
	init(&head_struct, envp);
	while (21)
	{
		head_struct.flag_pipe = 0;
		flows_change(&head_struct);
		write(1, "shell > ", 8);
		gnl_and_parser(&head_struct, &arg);
		ft_lstclear_args(&head_struct.list, free);
		head_struct.list = NULL;
	}
	flows_change(&head_struct);
	close(head_struct.saveinput);
	close(head_struct.saveoutput);
	return (1);
}
