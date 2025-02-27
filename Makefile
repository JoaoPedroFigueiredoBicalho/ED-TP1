# Nome do Programa
NAME = tp1.out

#Diretórios
OBJ_DIR = obj
INCLUDE_DIR = include
SRC_DIR = src

# Flags para o compilador
CPPFLAGS = -g -O3

# Arquivos de Origem e Objeto
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Regra Padrão
all: $(NAME)

# Regra para rodar o programa com o make
run: all
	bin/$(NAME) cad.r1000.p5000.xcsv

# Regra para construir o programa
$(NAME): $(OBJS)
	g++ $(CPPFLAGS) -I$(INCLUDE_DIR) -o bin/$@ $^

# Regra para os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -I$(INCLUDE_DIR) -c $< -o $@



clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f bin/$(NAME)