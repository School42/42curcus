/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:22:45 by talin             #+#    #+#             */
/*   Updated: 2024/10/24 14:45:55 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int	main() {
	const char	*filename = "example.txt";

	if (unlink(filename) == -1) {
		perror("Error unlinking file");
		return (1);
	}
	printf("File %s unlinkded successfully.\n", filename);
	return (0);
}