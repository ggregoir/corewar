# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    general.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 23:04:30 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/24 17:43:56 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GEN			=	get_name.c op.c print_error.c fill_binary.c get_options.c

SRC_GEN				=	$(addprefix $(SRC_GEN_PATH)/, $(SRCS_GEN))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_GEN:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_GEN_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
