HEADERS = ./Entidades/Componentes ./Entidades ./ ./Colisoes ./Gerenciadores ./Graficos . ./Listas ./Cenas ./Configs

OBJ = Jogo.o Entidade.o Componente.o Posicao.o Colisor.o Camera.o GerenciadorGrafico.o ImgSprite.o ImgTexto.o Grafico.o GraficoSprite.o ObjetoFisico.o GerenciadorColisoes.o CorpoRigido.o GerenciadorInputs.o EventoBotao.o Botao.o BotaoEntidade.o ListaEntidades.o Cena.o GerenciadorCenas.o Tempo.o CenaTeste.o Plataforma.o ControleJogador.o ControleAndador.o Ente.o ControleInimigo.o Projetil.o Jogador.o ControleExplodidor.o Movimento.o SeguidorCamera.o VidaUI.o ControleObstaculo.o ControleEspinho.o ControleSeiva.o ControleTrampolim.o MenuPrincipal.o MenuNovoJogo.o MenuPause.o Salvador.o MenuSalvar.o MenuCarregar.o Andador.o Explodidor.o Espinho.o Trampolim.o Seiva.o PlanicieAcoelhada.o ChefaoPulador.o ControleChefaoPulador.o NuvemAcoelhada.o

OBJ_DIR = ./obj
PROJ_NAME = JOGO
PRE_HEADERS = $(addprefix -I ,$(HEADERS))
FLAGS = -lm -Wall -std=c++2a -O2
CFLAGS = -Wall -std=c++2a -O2
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
$(OBJ_DIR)/CorpoRigido.o : Entidades/Componentes/CorpoRigido.cpp Colisoes/Colisor.h Colisoes/ObjetoFisico.h Entidades/Componentes/Componente.h Entidades/Componentes/Posicao.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
$(OBJ_DIR)/Botao.o : Entidades/Componentes/Botao.cpp Gerenciadores/EventoBotao.h Gerenciadores/GerenciadorGrafico.h Entidades/Componentes/Componente.h Entidades/Componentes/Posicao.h Entidades/Componentes/GraficoSprite.h Graficos/ImgTexto.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleJogador.o : Entidades/Componentes/ControleJogador.cpp Entidades/Componentes/ControleJogador.h  $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/Componente.o $(OBJ_DIR)/Posicao.o $(OBJ_DIR)/CorpoRigido.o $(OBJ_DIR)/Movimento.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleInimigo.o : Entidades/Componentes/ControleInimigo.cpp Entidades/Componentes/ControleInimigo.h  $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/Componente.o $(OBJ_DIR)/Posicao.o $(OBJ_DIR)/CorpoRigido.o $(OBJ_DIR)/Movimento.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
$(OBJ_DIR)/ControleAndador.o : Entidades/Componentes/ControleAndador.cpp Entidades/Componentes/ControleAndador.h $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/Componente.o $(OBJ_DIR)/Posicao.o $(OBJ_DIR)/CorpoRigido.o $(OBJ_DIR)/ControleInimigo.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleExplodidor.o : Entidades/Componentes/ControleExplodidor.cpp Entidades/Componentes/ControleExplodidor.h  $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/Componente.o $(OBJ_DIR)/Posicao.o $(OBJ_DIR)/CorpoRigido.o $(OBJ_DIR)/ControleInimigo.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleChefaoPulador.o : Entidades/Componentes/ControleChefaoPulador.cpp Entidades/Componentes/ControleChefaoPulador.h  $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/Componente.o $(OBJ_DIR)/Posicao.o $(OBJ_DIR)/CorpoRigido.o $(OBJ_DIR)/ControleInimigo.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Movimento.o : Entidades/Componentes/Movimento.cpp Entidades/Componentes/Movimento.h Configs/Tempo.h $(OBJ_DIR)/Componente.o 
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)m
	@ echo 'Compilando $@'
$(OBJ_DIR)/SeguidorCamera.o : Entidades/Componentes/SeguidorCamera.cpp Entidades/Componentes/SeguidorCamera.h  $(OBJ_DIR)/GerenciadorGrafico.o  $(OBJ_DIR)/Jogador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/VidaUI.o : Entidades/Componentes/VidaUI.cpp Entidades/Componentes/VidaUI.h  $(OBJ_DIR)/GerenciadorGrafico.o  $(OBJ_DIR)/Jogador.o  $(OBJ_DIR)/ImgSprite.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/MenuPrincipal.o : MenuPrincipal.cpp MenuPrincipal.h  $(OBJ_DIR)/GerenciadorInputs.o  $(OBJ_DIR)/Jogador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/MenuNovoJogo.o : MenuNovoJogo.cpp MenuNovoJogo.h  $(OBJ_DIR)/GerenciadorInputs.o  $(OBJ_DIR)/Jogador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/MenuPause.o : MenuPause.cpp MenuPause.h  $(OBJ_DIR)/GerenciadorInputs.o  $(OBJ_DIR)/Jogador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
$(OBJ_DIR)/MenuSalvar.o : MenuSalvar.cpp MenuSalvar.h  $(OBJ_DIR)/GerenciadorInputs.o  $(OBJ_DIR)/Salvador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/MenuCarregar.o : MenuCarregar.cpp MenuCarregar.h  $(OBJ_DIR)/GerenciadorInputs.o  $(OBJ_DIR)/Salvador.o  
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Filhos de Componente End
#Filhos de Entidade Start

#Filhos de Entidade End


#Lista Entidades
$(OBJ_DIR)/ListaEntidades.o : Listas/ListaEntidades.cpp Listas/ListaEntidades.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Cena
$(OBJ_DIR)/Cena.o : Cenas/Cena.cpp Cenas/Cena.h $(OBJ_DIR)/ListaEntidades.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'	
#Gerenciador Cenas
$(OBJ_DIR)/GerenciadorCenas.o : Gerenciadores/GerenciadorCenas.cpp  Gerenciadores/GerenciadorCenas.h $(OBJ_DIR)/Cena.o
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Tempo
$(OBJ_DIR)/Tempo.o : Configs/Tempo.cpp Configs/Tempo.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Salvador.o : Configs/Salvador.cpp Configs/Salvador.h 
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'


#Gerenciador de Colisoes
$(OBJ_DIR)/GerenciadorColisoes.o : Gerenciadores/GerenciadorColisoes.cpp  Gerenciadores/GerenciadorColisoes.h $(OBJ_DIR)/Colisor.o $(OBJ_DIR)/ObjetoFisico.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#ObjetoFisico
$(OBJ_DIR)/ObjetoFisico.o : Colisoes/ObjetoFisico.cpp $(OBJ_DIR)/Colisor.o Colisoes/IEscutaColisao.h
	@ g++ $(CFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#GerenciadorInputs
$(OBJ_DIR)/GerenciadorInputs.o : Gerenciadores/GerenciadorInputs.cpp  Gerenciadores/GerenciadorInputs.h $(OBJ_DIR)/GerenciadorGrafico.o $(OBJ_DIR)/EventoBotao.o  
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
#Evento Botao
$(OBJ_DIR)/EventoBotao.o : Gerenciadores/EventoBotao.cpp  $(OBJ_DIR)/Colisor.o Gerenciadores/EventoBotao.h  
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'

$(OBJ_DIR)/BotaoEntidade.o : Entidades/BotaoEntidade.cpp  Entidades/BotaoEntidade.h $(OBJ_DIR)/Botao.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Projetil.o : Entidades/Projetil.cpp  Entidades/Projetil.h $(OBJ_DIR)/Entidade.o $(OBJ_DIR)/Jogador.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Jogo.o : Jogo.cpp  Jogo.h $(OBJ_DIR)/GerenciadorCenas.o $(OBJ_DIR)/GerenciadorColisoes.o $(OBJ_DIR)/GerenciadorGrafico.o $(OBJ_DIR)/GerenciadorInputs.o $(OBJ_DIR)/Tempo.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Ente.o : Ente.cpp  Ente.h
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'

$(OBJ_DIR)/CenaTeste.o : Cenas/CenaTeste.cpp Cenas/CenaTeste.h $(OBJ_DIR)/Cena.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/PlanicieAcoelhada.o : Cenas/PlanicieAcoelhada.cpp Cenas/PlanicieAcoelhada.h $(OBJ_DIR)/Cena.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/NuvemAcoelhada.o : Cenas/NuvemAcoelhada.cpp Cenas/NuvemAcoelhada.h $(OBJ_DIR)/Cena.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Plataforma.o : Entidades/Plataforma.cpp Entidades/Plataforma.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Jogador.o : Entidades/Jogador.cpp Entidades/Jogador.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Andador.o : Entidades/Andador.cpp Entidades/Andador.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Explodidor.o : Entidades/Explodidor.cpp Entidades/Explodidor.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Espinho.o : Entidades/Espinho.cpp Entidades/Espinho.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Trampolim.o : Entidades/Trampolim.cpp Entidades/Trampolim.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/Seiva.o : Entidades/Seiva.cpp Entidades/Seiva.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ChefaoPulador.o : Entidades/ChefaoPulador.cpp Entidades/ChefaoPulador.h $(OBJ_DIR)/Entidade.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'

$(OBJ_DIR)/ControleObstaculo.o : Entidades/Componentes/ControleObstaculo.cpp Entidades/Componentes/ControleObstaculo.h
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleEspinho.o : Entidades/Componentes/ControleEspinho.cpp Entidades/Componentes/ControleEspinho.h $(OBJ_DIR)/ControleObstaculo.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleSeiva.o : Entidades/Componentes/ControleSeiva.cpp Entidades/Componentes/ControleSeiva.h $(OBJ_DIR)/ControleObstaculo.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'
$(OBJ_DIR)/ControleTrampolim.o : Entidades/Componentes/ControleTrampolim.cpp Entidades/Componentes/ControleTrampolim.h $(OBJ_DIR)/ControleObstaculo.o
	@ g++ $(CFLAGS) $(SFMLFLAGS) -c -o $@ $< $(PRE_HEADERS)
	@ echo 'Compilando $@'


clean:
	@ rm $(OBJ_DIR)/commons.o $(addprefix $(OBJ_DIR)/,$(OBJ)) 
	@ echo 'Removendo antigos .o'

#oi