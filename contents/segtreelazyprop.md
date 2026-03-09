# Segment Tree com Lazy Propagation

## Problema

Dado as operações:
<ol>
<li>Somar x em um intervalo <i>p</i> e <i>q</i>.</li>
<li>Imprimir a soma dos elementos em um intervalo <i>p</i> e <i>q</i>.</li>
</ol>

Bom, se essas operações fossem realizadas usando uma estrátegia de SegTree comum,  a primeira opção seria dar update em todos
esses elementos, sendo um p - q = x, teriamos $x \times log n$, que é uma complexidade ainda maior que se apenas percorre-se
o vetor linearmente. A segunda operação teria complexidade.

Assim a propagação preguiçosa entra com o objetivo de atualizar o valor de algo apenas quando for necessario, por exemplo,
se formos somar x no invervalo 1 a 3, e for consultar o intervalo 9 e 10, essa soma não seria necessária ter sido feita
naquele momento. **Será necessário criar um vetor para lazy**

## Funções
### Build
A função build continua semelhante a de segtree [SegTree](https://github.com/JuanHPassos/CompetitiveProgramming/tree/main/GEMA-USP/SegmentTree)

### Lazy Propagation

A função lazy propagation consiste em atualizar o no atual e passar a lazy para seus filhos.
Após isso, zera-se a lazy desse nó que foi atualizado.

### Update

Ao iniciar a função, chamda-se a lazy propagation para garantir que o nó esteja atualizado. Assim,
se o intervalo buscado não estiver cruzado com o intervalo atual, não é necessário conitnuar nesse caminho.
Agora, se estiver inteiramente contido, atualiza o valor na lazy propagation e encerra as chamadas, porém se estiver parcialmente contido, continua-se a propagar e após isso atualiza-se o nó de acordo com seus filhos. 

### query

Na função query, primeiro é necessário processara a lazy do nó atual.
Se o intervalo de busca não se cruzar com o intervalor atual, retorna-se nulo.
Caso contrário, caso o intervalor esteja inteiramente contido, retorna o valor desse nó.
E por ultimo, caso não seja nenhuma das opções anteriores, chama-se os filhos do nó.



