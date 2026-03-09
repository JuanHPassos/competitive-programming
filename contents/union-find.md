# Estrutura para unir árvore em log n
Consiste em dois vetor, um vetor de tamanho que guarda o tamanho da árvore que o elemento i está 
e um vetor de ligações, que guarda para onde o elemento aponta.

## Inicialização da estrutura
Começa-se com cada vértice sendo uma árvore(são seus representantes),
e cada árvore por consequencia tem tamanho 1.

```cpp
for (int i = 1; i <= n; i++) link[i] = i;
for (int i = 1; i <= n; i++) size[i] = 1;
```

## Encontrar representante da árvore
O representante é aquele que está ligado consigo mesmo
```cpp
int find(int x) 
{
 while (x != link[x]) x = link[x];
 return x;
}
```

## Fusão entre duas árvores
Pegar o representante da menor árvore e faze-lo apontar para o representante da maior árvore.
Tal implementação evita árvore muito altas e garante log n.
```cpp
void unite(int a, int b) 
{
  a = find(a);
  b = find(b);
  if (size[a] < size[b]) swap(a,b);
  size[a] += size[b];
  link[b] = a;
}
```

## Verificar se está na mesma árvore
Basta ver se os representantes dessa árvore são iguais.
```cpp
bool same(int a, int b) 
{
 return find(a) == find(b);
}
```