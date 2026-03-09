# Tipos de dados
Inteiro de 32 bits(4 bytes): $\pm 2 \times 10^9$ 

Inteiro de 64 bits(8 bytes): $\pm 9 \times 10^{18}$

# Complexidade de espaço e tempo
Formulas matemáticas que apenas calculam a resposta: $O\left(1\right)$

Set e map desordenados : $O\left(1\right)$ por operação.

Busca binária: $O\left(\log (n) \right)$

Set e map ordenados ou filas de prioridade: $O\left(\log (n)\right)$ por operação.

Fatoração prima de um número inteiro ou verificação de primalidade ou composição de um número inteiro: $O\left(\log (n)\right)$

Ler n itens: $O\left(n\right)$

Percorrer lista ou vetor com n elementos: $O\left(n\right)$

Ordenação padrão: $O\left(n \ \log (n)\right)$

Iterar por todos os subconjuntos de tamanho k: $O\left(n^k\right)$

Iterar por todos os subconjuntos: $O\left(2^n\right)$

Iterar por todas as permutações: $O\left(n!\right)$

## Dica de complexidade a partir do n

| n             | Complexidade possível      |
|---------------|----------------------------|
| $n \leq 10$   |  $O\left(n!\right)$, $O\left(n^7\right)$, $O\left(n^6\right)$ |          
| $n \leq 20$   |  $O\left(2^n \cdot n\right)$, $O\left(n^5\right)$          |
| $n \leq 80$   |  $O\left(n^4\right)$ |          
| $n \leq 400$   |  $O\left(n^3\right)$ |          
| $n \leq 7500$   |  $O\left(n^2\right)$ |          
| $n \leq 7 \cdot 10^4$   |  $O\left(n\sqrt{n}\right)$ |          
| $n \leq 5 \cdot 10^5$   |  $O\left(n \cdot \log (n)\right)$ | 
| $n \leq 5 \cdot 10^6$   |  $O\left(n \right)$ | 
| $n \leq 10^12$   |  $O\left(\sqrt{n} \cdot \log (n)\right)$, $O\left(\sqrt{n}\right)$ | 
| $n \leq 10^{18}$   |  $O\left(\log^2 (n)\right)$, $O\left(\log (n)\right)$, $O\left( 1 \right)$ | 

# Estruturas de dados

## Iteradores

Iteradores são semelhantes aos ponteiros, por exemplo, dado vector.begin() é retorna um ponteiro para o início de um vetor. São declarados de maneira fácil usando "auto", por exemplo:
```cpp
 for(auto element : v) {
 cout << element; //prints the values in the vector
 }

// OU

auto pointer = v.begin();
```

## Vetores dinâmicos

Vetores que pdem regular o seu tamanho, com inserção e remoção no fim em $O(1)$. Para operações no meio do vetor, $O(n)$.

vector<int> vetor; -> criar vetor dinâmico.

v.push_back(número) -> adiciona número no fim do vetor.

v.erase(v.begin() + 1) -> remove elemento no index 1.

v.erase(v.end() - 1) -> remove o ultimo elemento.

v.erase(v.begin(), v.begin() + 3) -> Apaga os primeiros 3 elementos.

Ordenar vetores dinamicos: sort(v.begin(), v.end())

Ordenar vetores estaticos: sort(arr, arr + N)

## Pilhas

Inseri e remove em O(1), seguindo a lógica de Last In First Out(LIFO).

stack<int> pilha; -> cria pilha.

pilha.push(número) -> empilha número.

pilha.pop() -> desempilha número.

pilha.top() -> retorna topo da pilha.

pilha.size() -> retorna tamanho da pilha.

## Filas

Inseri e remove em O(1), seguindo lógica First In First Out(FIFO)

queue<int> fila; -> cria fila.

fila.push(número) -> insere número no fim da fila.

fila.pop() -> remove da frente da fila.

fila.front() -> retorna frente da fila.

fila.size() -> retorna tamanho da fila.

## Deques

Combinação da fila e pilha.

deque<int> d;

d.push_front(1) -> insere no início.

d.push_back(2) -> insere no fim.

d.pop_back() -> remove elemento do fim.

d.pop_front() -> remove elemento do inicio.

## Priority queues

Deleta e inserir elemento em $log (n)$, além de manter elemento de maior prioridade na frente da fila.

Declaração comum:
priotiry_queue<int> pq;

Declaração específica:
priotiry_queue<int, vector<int>, Compare> pq;
Parâmetros:
1. elemento que será armazenado na fila.
2. onde os elementos serão guardados.
3. Define prioridade(less<int> para prioridade máxima(definida por padrão) e greater<int> minima).

pq.push(número) -> adiciona elemento.
pq.top() -> retorna frente da fila
pq.pop() -> remove frente da fila.

# Set

### Set não ordenado

Guarda elemento em O(1) usando hashing.

Declaração:
unordered_set<int> set;

Inserção:
set.insert(1); // Insere elemento 1.

Verifica se elemento está no set:
set.count(1); // Retorna true ou false.

Remoção:
set.count(0);

### Set ordenado
Ocorre todas as operações em $O(\log (n))$.
Operções adicionais:

- Retorna ponteiro para o elemento maior ou igual ao elemento passado como argumento
set.upper_bound(7); 

- Retorna ponteiro para o elemento maior ao buscado 
set.upper_bound(7);

- Retorna ponteiro para primeira posição do set.
set.begin();

- Retorna ponteiro para uma posição após o ultimo elemento do set.
-  Ponteiro para o ultimo elemento é (--(set.end()));
set.end();

- Apaga elemento do set em que o ponteiro está apontando.
set.erase(set.upper_bound(6));

# Maps

Possui map ordenado e não ordenado.

### Unordered map

Implementado por meio de uma tabela hash e tem custo constante.

```cpp
unordered_map<int, int> m;
m[1] = 5; // [(1, 5)]
m[3] = 14; // [(1, 5); (3, 14)]
m[2] = 7; // [(1, 5); (3, 14); (2, 7)]
m.erase(2); // [(1, 5); (3, 14)]
cout << m[1] << '\n'; // 5
cout << m.count(7) << '\n' ; // 0
cout << m.count(1) << '\n' ; // 1
```

### Ordered Maps

Implementado com uma árvore, possui operações em log n.

```cpp
 map<int, int> m;
 m[3] = 5; // [(3, 5)]
 m[11] = 4; // [(3, 5); (11, 4)]
 m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
 cout << m.lower_bound(10)->first << ""<< m.lower_bound(10)->second << '\n';
// Printa 10 491
 cout << m.upper_bound(10)->first << ""<< m.upper_bound(10)->second << '\n';
// Printa 11 4
 m.erase(11); // [(3, 5); (10, 491)]
 if (m.upper_bound(10) == m.end())
 {
 cout << "end" << endl; // Prints end
 }
```

### Multisets

É um set que permite repetição, tem custo O(log n + f) sendo f o número de elementos repetidos de um determinado valor.

Declaração:
multiset<int> ms;

Inserção:
ms.insert(1);

Busca:
Retorna quantidade desse elemento no conjunto.
ms.count(1);

Remoção:
Remova todos os 1 do conjunto.
ms.erase(1);
Remove apenas aonde o ponteiro aponta
ms.erase(ms.find(1))






