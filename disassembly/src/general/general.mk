# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    general.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 23:04:30 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/08 22:06:58 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GEN			=	op.c print_error.c check_argv.c reset_buffer.c \
						get_path.c line_dup.c

SRC_GEN				=	$(addprefix $(SRC_GEN_PATH)/, $(SRCS_GEN))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_GEN:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_GEN_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
