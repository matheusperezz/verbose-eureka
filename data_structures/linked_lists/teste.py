# classe Nodo
class Nodo:
    def __init__(self, dado=0, proximo_nodo=None):
        self.conteudo = dado
        self.proximo = proximo_nodo

    def __repr__(self):
        return '%s -> %s' % (self.conteudo, self.proximo)

# programa principal de teste
Nd = Nodo()
print(Nd)

Nd2 = Nodo("casa")
print(Nd2)


# CRIAÇÃO DA CLASSE ListaEncadeada
# classe lista encadeada
class ListaEncadeada:

    def __init__(self):
        self.inicio = None

    def __repr__(self):
        return "[" + str(self.inicio) + "]"

    # CRIAÇÃO DA FUNÇÃO Remove_Pos
    def Remove_Pos(self,pos):
        atual = self.inicio
        pos_atual = 0

    # verifica se a posição a ser removida é a primeira; se positivo, atualiza o elemento de início da lista
        if pos_atual == pos:
            self.inicio = atual.proximo

    # se a posição a ser removida não é a primeira, percorre a lista até achar a posição anterior à desejada para a troca dos ponteiros
        else:
            while atual.proximo != None:

                if pos_atual == (pos-1):
                    next = atual.proximo
                    atual.proximo = next.proximo
                else:
                    atual = atual.proximo

                pos_atual = pos_atual + 1

    # CRIAÇÃO DA FUNÇÃO Adiciona_Fim
    def Adiciona_Fim(self, item):

    # verifica se a lista não está vazia para percorrer, pois, se estiver, irá adicionar no início
        if self.inicio:
            aux = self.inicio

    # percorre a lista até o último elemento
            while (aux.proximo):
                aux = aux.proximo
                # quando sair do laço é porque chegou no último elemento; Logo, atualiza o último elemento a receber como proximo o novo elemento
            aux.proximo = item

    # como a lista está vazia, adiciona no início da lista
        else:
            self.inicio = item


# programa principal de teste
lista = ListaEncadeada()

Nd = Nodo("A")
lista.Adiciona_Fim(Nd)
print("lista: ", lista)

Nd2 = Nodo("B")
lista.Adiciona_Fim(Nd2)
print("lista: ", lista)

Nd3 = Nodo("C")
lista.Adiciona_Fim(Nd3)
print("lista: ", lista)

lista.Remove_Pos(2)
print("lista: ", lista)

lista.Remove_Pos(0)
print("lista: ", lista)
