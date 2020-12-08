import java.util.*

data class Command(val cmd: String, val value: Int)

fun flipCommand(cmd: Command): Command {
  return when(cmd.cmd) {
    "nop" -> Command("jmp", cmd.value)
    "jmp" -> Command("nop", cmd.value)
    else -> cmd
  }
}

fun execute(commands: List<Command>): Int? {
  var line = 0
  var acc = 0
  val executedLines = mutableSetOf<Int>()
  while (line != commands.size) {
    if(line in executedLines || line !in commands.indices) {
      return null
    }

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
  return acc
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  val commands = mutableListOf<Command>()
  while (s.hasNext()) {
    commands.add(Command(s.next(), s.nextInt()))
  }

  for(i in commands.indices) {
    commands[i] = flipCommand(commands[i])
    execute(commands).let { if(it != null) println(it) }
    commands[i] = flipCommand(commands[i])
  }
}
