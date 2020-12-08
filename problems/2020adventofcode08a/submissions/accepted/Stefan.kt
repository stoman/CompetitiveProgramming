import java.util.*

data class Command(val cmd: String, val value: Int)

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  val commands = mutableListOf<Command>()
  while (s.hasNext()) {
    commands.add(Command(s.next(), s.nextInt()))
  }

  var line = 0
  var acc = 0
  val executedLines = mutableSetOf<Int>()
  while (line !in executedLines) {
    executedLines.add(line)
    when (commands[line].cmd) {
      "nop" -> line++
      "acc" -> {
        acc += commands[line].value
        line++
      }
      "jmp" -> line += commands[line].value
    }
  }
  println(acc)
}
