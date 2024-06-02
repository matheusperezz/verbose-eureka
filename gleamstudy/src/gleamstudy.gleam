import gleam/io

pub fn () {
  io.println("Hello from gleamstudy!")
  let result1 = string_to_int("123")
  print_result(result1)

  let result2 = string_to_int("abc")
  print_result(result2)
}

pub fn string_to_int(input: String) -> Result(Int, String) {
  case String.to_int(input) {
    Ok(num) -> Ok(num)
    Error(_) -> Error("Falha ao converter a string para inteiro".to_string())
  }
}

fn print_result(result: Result(Int, String)) {
  case result {
    Ok(num) -> io.println("Conversao bem sucedida: " <> Int.to_string(num))
    Error(err) -> io.println("Erro: " <> err)
  }
}
