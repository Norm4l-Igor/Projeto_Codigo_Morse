# Projeto 1 — Código Morse

**Disciplina:** Algoritmos e Programação II  
**Universidade Presbiteriana Mackenzie — FCI**  
**Turma:** 02A — Campus Alphaville

## Integrantes

| Nome | RA |
|------|----|
| Breno Zanolla Bittencourt | 10753877 |
| Igor Vieira Guedes Oliveira | 10751928 |

---

## Compilação

```bash
gcc -o morse morse.c
```

## Execução

```bash
./morse
```

O programa lê uma única linha da entrada padrão (até 200 caracteres) e imprime a mensagem decodificada.

---

## Exemplos de Entrada e Saída

### Exemplo 1 — Alfabeto completo (sem corrupção)

**Entrada:**
```
.- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..
```
**Saída:**
```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

---

### Exemplo 2 — Frase com letra corrompida

**Entrada:**
```
-.-. .- -.. .-*  -- .- -.-. .- -.-. ---  -. ---  ... . ..-  --. .- .-.. .... ---
```
**Saída:**
```
CAD[AJLPRW] MACACO NO SEU GALHO
```

> `.-*` → prefixo `.-` → A, J, L, P, R, W → `[AJLPRW]`

---

### Exemplo 3 — Prefixo de um único símbolo

**Entrada:**
```
-*  --- .-. ... ---
```
**Saída:**
```
[BCDGKMNTVXYZ] ORSO
```

> `-*` → todas as letras cujo código começa com `-`: B C D G K M N T V X Y Z

---

### Exemplo 4 — Múltiplas letras corrompidas

**Entrada:**
```
... ---  ...*  -- ..*
```
**Saída:**
```
SO[HS] M[FHISUV]
```

> `...*` → prefixo `...` → H (....), S (...) → `[HS]`  
> `..*` → prefixo `..` → F, H, I, S, U, V → `[FHISUV]`

---

### Exemplo 5 — Palavra única com corrupção no início

**Entrada:**
```
-* .-. . ..
```
**Saída:**
```
[BCDGKMNTVXYZ]REI
```
