// Screen Sound
void ExibirMensagemDeBoasVindas()
{
    Console.WriteLine(@"
█████████████████████████████████████████████████████████████████████████
█─▄▄▄▄█─▄▄▄─█▄─▄▄▀█▄─▄▄─█▄─▄▄─█▄─▀█▄─▄███─▄▄▄▄█─▄▄─█▄─██─▄█▄─▀█▄─▄█▄─▄▄▀█
█▄▄▄▄─█─███▀██─▄─▄██─▄█▀██─▄█▀██─█▄▀─████▄▄▄▄─█─██─██─██─███─█▄▀─███─██─█
▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▀▀▄▄▀▀▀▄▄▄▄▄▀▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▀▀▄▄▀▄▄▄▄▀▀
    ");
    Console.WriteLine("Boas vindas ao Screen Sound!");
}

void ExibirOpcoesDoMenu()
{
    Console.WriteLine("Digite um número para efetuar uma ação:");
    Console.WriteLine("1 - Registrar uma banda");
    Console.WriteLine("2 - Mostrar todas as bandas");
    Console.WriteLine("3 - Avaliar uma banda");
    Console.WriteLine("4 - Exibir média de uma banda");
    Console.WriteLine("0 - Sair");

    Console.Write("\nDigite sua opção: ");
    string acaoEscolhida = Console.ReadLine()!;
    int acaoEscolhidaNumerica = int.Parse(acaoEscolhida);

    switch (acaoEscolhidaNumerica)
    {
        case 1:
            RegistrarBanda();
            break;

        case 2:
            Console.WriteLine($"Você escolheu a opção {acaoEscolhida}");
            break;

        case 3:
            Console.WriteLine($"Você escolheu a opção {acaoEscolhida}");
            break;

        case 4:
            Console.WriteLine($"Você escolheu a opção {acaoEscolhida}");
            break;

        case 0:
            Console.WriteLine($"Tchau ;)");
            break;

        default:
            Console.WriteLine("Escolha uma opção válida.");
            break;
    }

}

void RegistrarBanda()
{
    Console.Clear();
    Console.WriteLine("Registro de bandas");
    Console.Write("Digite o nome da banda que deseja cadastrar: ");
    string nomeDaBanda = Console.ReadLine()!;
    Console.WriteLine($"A banda {nomeDaBanda} foi registrada!");
    Thread.Sleep(1500);
    Console.Clear();
    ExibirMensagemDeBoasVindas();
    ExibirOpcoesDoMenu();
}

ExibirMensagemDeBoasVindas();
ExibirOpcoesDoMenu();