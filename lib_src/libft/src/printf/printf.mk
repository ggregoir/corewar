# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    printf.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 20:45:57 by iburel            #+#    #+#              #
#    Updated: 2017/12/17 22:57:34 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCL_PRINTF				=	$(INCL_PATH)/ft_printf.h

SRC_CONVPRINTF_PATH		=	$(SRC_PRINTF_PATH)/conv
SRC_TYPEPRINTF_PATH		=	$(SRC_PRINTF_PATH)/type
SRC_FLAGSPRINTF_PATH	=	$(SRC_PRINTF_PATH)/flags

include $(SRC_CONVPRINTF_PATH)/conv.mk
include $(SRC_TYPEPRINTF_PATH)/type.mk
include $(SRC_FLAGSPRINTF_PATH)/flags.mk

SRCS_PRINTF				=	ft_printf.c ft_sprintf.c ft_fprintf.c ft_vprintf.c \
							ft_vsprintf.c ft_vfprintf.c pf_buff.c spf_buff.c \
							fpf_buff.c pf_conv.c pf_tags.c pf_prec.c pf_arg.c \
							pf_itoa.c pf_uitoa_base.c pf_fill.c pf_putchar.c
SRC_PRINTF				=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJS_PRINTF				=	$(SRCS_PRINTF:.c=.o) $(SRCS_CONVPRINTF:.c=.o) $(SRCS_TYPEPRINTF:.c=.o) $(SRCS_FLAGSPRINTF:.c=.o)


$(OBJ_PATH)/%.o: $(SRC_PRINTF_PATH)/%.c $(INCL_PRINTF)
	$(CC) -o $@ -c $< -I $(INCL_PATH) $(CFLAGS)