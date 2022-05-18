HEADERS = ./Entidades/Componentes ./Entidades . ./ ./Colisoes ./Gerenciadores ./Graficos ./Listas ./Cenas ./Configs
OBJ = Entidade.o Componente.o Posicao.o Colisor.o Camera.o GerenciadorGrafico.o ImgSprite.o ImgTexto.o Grafico.o GraficoSprite.o ListaEntidades.o Cena.o GerenciadorCenas.o Tempo.o
OBJ_DIR = ./obj
PROJ_NAME = JOGO
PRE_HEADERS = $(addprefix -I ,$(HEADERS))
FLAGS = -lm -Wall
CFLAGS = -Wall
FINALFILES = main.cpp
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
all: $(PROJ_NAME)

$(PROJ_NAME) : $(FINALFILES) $(OBJ_DIR)/commons.o $(addprefix $(OBJ_DIR)/,$(OBJ))
	@ echo 'Ligando partes: $(FINALFILES) $(OBJ_DIR)/commons.o $(addprefix $(OBJ_DIR)/,$(OBJ))'
	@ g++  $^ -o $(PROJ_NAME) $(PRE_HEADERS) $(FLAGS) $(SFMLFLAGS)
	@ echo 'Compilacao finalizada, nome do executavel: $(PROJ_NAME)'
	
#Bibliotecas pre compiladas
$(OBJ_DIR)/commons.o : commons.cpp commons.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Entidade Geral
$(OBJ_DIR)/Entidade.o : Entidades/Entidade.cpp Entidades/Entidade.h Entidades/Componentes/Componente.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Componente Geral
$(OBJ_DIR)/Componente.o : Entidades/Componentes/Componente.cpp Entidades/Componentes/Componente.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Colisor
$(OBJ_DIR)/Colisor.o : Colisoes/Colisor.cpp Colisoes/Colisor.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Camera
$(OBJ_DIR)/Camera.o : Graficos/Camera.cpp  Graficos/Camera.h Colisoes/Colisor.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'

#Filhos de Imagem start
$(OBJ_DIR)/ImgSprite.o : Graficos/ImgSprite.cpp  Graficos/ImgSprite.h Graficos/Imagem.h Colisoes/Colisor.h Gerenciadores/GerenciadorGrafico.h
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ImgTexto.o : Graficos/ImgTexto.cpp  Graficos/ImgTexto.h Graficos/Imagem.h Colisoes/Colisor.h Gerenciadores/GerenciadorGrafico.h
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Filhos de Imagem end
#Gerenciador Grafico
$(OBJ_DIR)/GerenciadorGrafico.o : Gerenciadores/GerenciadorGrafico.cpp  Gerenciadores/GerenciadorGrafico.h Graficos/Imagem.h $(OBJ_DIR)/Camera.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Filhos de Componente Start
$(OBJ_DIR)/Posicao.o : Entidades/Componentes/Posicao.cpp Entidades/Componentes/Posicao.h Entidades/Componentes/Componente.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Grafico.o : Entidades/Componentes/Grafico.cpp Entidades/Componentes/Grafico.h Entidades/Componentes/Componente.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/GraficoSprite.o : Entidades/Componentes/GraficoSprite.cpp Entidades/Componentes/GraficoSprite.h Entidades/Componentes/Grafico.h Entidades/Componentes/Componente.h Entidades/Componentes/Posicao.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Filhos de Componente End
#Filhos de Entidade Start

#Filhos de Entidade End

#Lista Entidades
$(OBJ_DIR)/ListaEntidades.o : Listas/ListaEntidades.cpp Listas/ListaEntidades.h Entidades/Entidade.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Cena
$(OBJ_DIR)/Cena.o : Cenas/Cena.cpp Cenas/Cena.h Listas/ListaEntidades.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'	
#Gerenciador Cenas
$(OBJ_DIR)/GerenciadorCenas.o : Gerenciadores/GerenciadorCenas.cpp  Gerenciadores/GerenciadorCenas.h Cenas/Cena.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Tempo
$(OBJ_DIR)/Tempo.o : Configs/Tempo.cpp Configs/Tempo.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'

clean:
	@ rm $(OBJ_DIR)/commons.o $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	@ echo 'Removendo antigos .o'