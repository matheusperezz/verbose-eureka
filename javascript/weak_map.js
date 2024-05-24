/**
Diferenças entre WeakMap e Map Também pode se aplicar a WeakSet e Set
Gerenciamento de memória:

Map: As chaves e os valores são mantidos na memória enquanto o Map existir. Mesmo que não haja mais referências às chaves, elas não serão coletadas pelo garbage collector.
WeakMap: As chaves são referenciadas fracamente, permitindo que o garbage collector remova automaticamente uma chave (e o valor associado) se não houver outras referências a essa chave.
Tipo de chave:

Map: As chaves podem ser de qualquer tipo, incluindo objetos, primitivos, etc.
WeakMap: As chaves devem ser objetos.
Iterabilidade e métodos de enumeração:

Map: Iterável, fornece métodos como keys(), values(), e entries().
WeakMap: Não iterável, não fornece métodos para obter todas as chaves ou valores.
 */

// Exemplo de uso do WeakMap
const weakMap = new WeakMap();
let obj = {};

weakMap.set(obj, "value");
console.log(weakMap.get(obj)); // value
console.log(weakMap.has(obj)); // true

obj = null; // A chave agora é colecionável pelo garbage collector