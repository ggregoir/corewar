# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 22:39:09 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/12 14:51:34 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PARSE			=	parse_file.c get_instructions.c store_line.c \
						parse_arguments.c store_argument.c get_opcode.c \
						add_instruction.c get_next_arg.c word_equal.c \
						get_header.c parse_name.c parse_comment.c check_syntax.c

SRC_PARSE			=	$(addprefix $(SRC_PARSE_PATH)/, $(SRCS_PARSE))

OBJ					+=	$(addprefix $(OBJ_PATH)/, $(SRCS_PARSE:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_PARSE_PATH)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
