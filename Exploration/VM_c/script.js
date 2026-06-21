async function test() {
    const {instance} = await WebAssembly.instantiateStreaming(fetch("./wasmtext.wasm"));

    const {sum} = instance.exports;

    console.log("A soma 5 + 3 é: ", sum(5, 3));
    return sum(5, 3);
}

test().catch((e) => console.error("Erro ao carregar o WASM:", e));
