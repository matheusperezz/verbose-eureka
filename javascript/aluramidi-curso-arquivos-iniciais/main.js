function tocarSom(idElemento){
    let texto = `#som_${idElemento.toLowerCase()}`
    console.log(texto)
    document.querySelector(texto).play();
}

const listaTeclas = document.querySelectorAll('.tecla');

listaTeclas.forEach((botao) => {
    botao.onclick = function () {
        tocarSom(botao.classList[1])
    };
})