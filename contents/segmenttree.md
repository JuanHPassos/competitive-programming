# Segment Tree

Esse algoritmo consiste em uma árvore binária que cada nó guarda uma informação de um intervalo de um vetor.
Tem como objetivo otimizar operações de busca e atualização com complexidade, tornando complexidade $O(\log n)$.
A complexidade total do algoritmo é $O(n + q*\log n)$, sendo que a `q` quantidade de operações, 
$log n$ vem do custo de cada operação e n para construir a árvore binária.

O código conterá 2 vetores:
- Vetor com os valores(n + 1, usa-se 1 indexado)
- Vetor de nós(4*n, `confia`)

O algoritmo conterá 4 funções:
- Construir árvore binária
- Atualizar
- Busca/Consulta
- Fusão

## Função construir

Basicamente essa função, irá preencher a árvore recursivamente, tendo como parametro, o vetor que contem os valores,
a posição do no atual, inicialmente 1, e o intervelo representado por L e R, o filho esquerdo é chamado por 2 * no atual,
tendo como intervalo de L a mid, e o direito por 2*n + 1, tendo como intervalo de mid+1 a R. Tal recursão se mantem
até o intervalor ter tamanho 1, após isso, volta-se na recursão fundindo os valores dos filhos para o pai. Exemplo: se o 
no guarda a soma de um intervalo, o pai guardara a soma de seus filhos.(Altura da árvore de recursão é $Log n$)

## Função atualizar

A função irá descer até o nó em que se deseja atualizar o valor, e voltara na recursão atualizando a arvore por meio
da fusão dos filhos para o pai. Tendo como parametro o no atual, L e R, mas agora com o parametro id que é a folha procurada,
e o seu novo valor `x`. Nota-se que não há necessidade de descer no caminho que id não estiver incluso.

## Função busca

Nessa função têm-se como parametro o intervalo p e q que se deseja a informação, portanto, é passado como parametro,
o nó atual, o intervalo l e r, e o intervalo que se busca p e q. Nota-se que caso não há cruzamento entre o intervalo buscado
e o intervalo L e R, não há necessidade de continuar esse caminho(retorna neutro).
E caso o intervalo L e R esteja inteiramente contido no intervalo p e q, retorna o seu valor,
tendo em vista que esse faz parte da resposta. OBS: chamada das funções por meio de uma operação.(soma, min, max...)

## Função fusão

Essa função se restringe para caso mais gerais, pois em nós que so se guarda soma, a fusão é a soma desses dois nós,
no entanto, para caso mais gerais, essa fusão depende da informação que será guardada no nó.

