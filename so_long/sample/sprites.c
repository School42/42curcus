/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:42:28 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 11:54:07 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_p_sprites(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * (SI_PMAX + 1));
	if (!sprites)
		return (NULL);
	sprites[0] = "./assets/sprites/locke_fu1.png";
	sprites[1] = "./assets/sprites/locke_fu2.png";
	sprites[2] = "./assets/sprites/locke_fu3.png";
	sprites[3] = "./assets/sprites/locke_fr1.png";
	sprites[4] = "./assets/sprites/locke_fr2.png";
	sprites[5] = "./assets/sprites/locke_fr3.png";
	sprites[6] = "./assets/sprites/locke_fd1.png";
	sprites[7] = "./assets/sprites/locke_fd2.png";
	sprites[8] = "./assets/sprites/locke_fd3.png";
	sprites[9] = "./assets/sprites/locke_fl1.png";
	sprites[10] = "./assets/sprites/locke_fl2.png";
	sprites[11] = "./assets/sprites/locke_fl3.png";
	sprites[12] = "./assets/sprites/locke_won.png";
	sprites[13] = "./assets/sprites/locke_lost.png";
	return (sprites);
}

char	**get_font_sprites(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * 11);
	if (!sprites)
		return (NULL);
	sprites[0] = "./assets/sprites/d_0.png";
	sprites[1] = "./assets/sprites/d_1.png";
	sprites[2] = "./assets/sprites/d_2.png";
	sprites[3] = "./assets/sprites/d_3.png";
	sprites[4] = "./assets/sprites/d_4.png";
	sprites[5] = "./assets/sprites/d_5.png";
	sprites[6] = "./assets/sprites/d_6.png";
	sprites[7] = "./assets/sprites/d_7.png";
	sprites[8] = "./assets/sprites/d_8.png";
	sprites[9] = "./assets/sprites/d_9.png";
	sprites[10] = "./assets/sprites/d_slash.png";
	return (sprites);
}

char	**get_misc_sprites(void)
{
	char	**sprites;

	sprites = (char **)malloc(sizeof(char *) * SI_MAX);
	if (!sprites)
		return (NULL);
	sprites[0] = "./assets/sprites/floor.png";
	sprites[1] = "./assets/sprites/wall.png";
	sprites[2] = "./assets/sprites/wall_r.png";
	sprites[3] = "./assets/sprites/wall_d.png";
	sprites[4] = "./assets/sprites/wall_l.png";
	sprites[5] = "./assets/sprites/chest_opened.png";
	sprites[6] = "./assets/sprites/obs1.png";
	sprites[7] = "./assets/sprites/obs2.png";
	sprites[8] = "./assets/sprites/col1.png";
	sprites[9] = "./assets/sprites/col2.png";
	sprites[10] = "./assets/sprites/mon1.png";
	sprites[11] = "./assets/sprites/mon2.png";
	sprites[12] = "./assets/sprites/locke_fd2.png";
	sprites[13] = "./assets/sprites/locke_won.png";
	sprites[14] = "./assets/sprites/exit.png";
	sprites[15] = "./assets/sprites/d_moves.png";
	return (sprites);
}
