const html = document.querySelector('html');
const focoBt = document.querySelector('.app__card-button--foco');
const curtoBt = document.querySelector('.app__card-button--curto');
const longoBt = document.querySelector('.app__card-button--longo');
const banner = document.querySelector('.app__image');
const titulo = document.querySelector('.app__title');
const botoes = document.querySelectorAll('.app__card-button')
const checkboxMusica = document.querySelector('#alternar-musica');
const startPauseBt = document.querySelector('#start-pause');
const startPauseTexto = document.querySelector('#start-pause span');
const startPauseImage = document.querySelector('.app__card-primary-butto-icon');
const timer = document.querySelector('#timer')

// Foco 25min
let tempoDecorridoEmSegundos = 25 * 60;
let intervaloId = null
let emContagem = false

/** Audios **/
const musicaLuna = new Audio('./sons/luna-rise-part-one.mp3');
const musicaBeep = new Audio('./sons/beep.mp3');
const musicaPlay = new Audio('./sons/play.wav');
const musicaPause = new Audio('./sons/pause.mp3');

checkboxMusica.addEventListener('change', () => {
    tocarMusica(musicaLuna)
})

focoBt.addEventListener('click', () => {
    alterarContexto('foco');
    focoBt.classList.add('active');
});

curtoBt.addEventListener('click', () => {
    alterarContexto('descanso-curto');
    curtoBt.classList.add('active');
});

longoBt.addEventListener('click', () => {
    alterarContexto('descanso-longo');
    longoBt.classList.add('active');
});

function alterarContexto(contexto) {

    botoes.forEach(function (contexto) {
        contexto.classList.remove('active');
    });

    html.setAttribute('data-contexto', contexto);
    banner.setAttribute('src', `./imagens/${contexto}.png`);
    switch (contexto) {
        case 'foco':
            titulo.innerHTML = `
            Otimize sua produtividade,<br>
                <strong class="app__title-strong">mergulhe no que importa.</strong>
            `
            tempoDecorridoEmSegundos = 25 * 60
            mudarTimer(tempoDecorridoEmSegundos)
            break;
        case 'descanso-curto':
            titulo.innerHTML = `
            Que tal dar uma respirada?<br>
                <strong class="app__title-strong">Faça uma pausa curta!</strong>
            `
            tempoDecorridoEmSegundos = 5 * 60
            mudarTimer(tempoDecorridoEmSegundos)
            break;
        case 'descanso-longo':
            titulo.innerHTML = `
            Hora de voltar à superfície.<br>
                <strong class="app__title-strong"> Faça uma pausa longa.</strong>
            `
            tempoDecorridoEmSegundos = 10 * 60
            mudarTimer(tempoDecorridoEmSegundos)
            break;
    }

}

const contagemRegressiva = () => {
    if (tempoDecorridoEmSegundos <= 0){
        zerar();
        // musicaBeep.play();
        alert('Tempo finalizado');
        return;
    }
    tempoDecorridoEmSegundos -= 1;
    mudarTimer(tempoDecorridoEmSegundos)
}

startPauseBt.addEventListener('click', toggleIntervalo);

function toggleIntervalo(){

    if (intervaloId){
        zerar()
    }
    if (emContagem){
        // Pausou
        musicaPause.play()
        startPauseImage.setAttribute('src', './imagens/play_arrow.png')
        startPauseTexto.textContent = 'Começar'
        clearInterval(intervaloId)
    } else {
        // Ativou o contador
        startPauseTexto.textContent = 'Pausar'
        startPauseImage.setAttribute('src', './imagens/pause.png')
        musicaPlay.play()
        intervaloId = setInterval(contagemRegressiva, 1000);
    }

    emContagem = !emContagem
}

function zerar() {
    clearInterval(intervaloId);
    intervaloId = null;
}

function tocarMusica(musica){
    if (musica.paused){
        musica.play()
    } else {
        musica.pause()
    }
}
function mudarTimer(tempoEmSegundos){
    let minuto = Math.floor(tempoEmSegundos / 60)
    let segundo = Math.floor(tempoEmSegundos % 60)
    if (segundo === 0){
        timer.textContent = `${minuto}:00`
    } else {
        timer.textContent = `${minuto}:${segundo}`
    }
}