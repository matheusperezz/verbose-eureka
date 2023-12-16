function tocarSom(idElemento){
    let texto = `#som_${idElemento.toLowerCase()}`
    document.querySelector(texto).play();
}

const listaTeclas = document.querySelectorAll('.tecla');

listaTeclas.forEach((botao) => {
    botao.onclick = function () {
        tocarSom(botao.classList[1]);
    };

    botao.onkeydown = function (event) {
        if (event.key === 'Enter' || event.key === 'Space '){
            botao.classList.add('ativa');
        }
    }

    botao.onkeyup = function () {
        botao.classList.remove('ativa');
    }
})