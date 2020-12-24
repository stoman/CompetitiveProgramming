import java.util.*

fun moveToEnd(cups: List<Int>, end: Int): List<Int> {
  val pos = cups.indexOf(end)
  val move = cups.size - pos - 1
  return cups.takeLast(move) + cups.dropLast(move)
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)
  var cups = s.next().map { it.toString().toInt() }
  repeat(100) {
    val active = cups[0]
    val three = cups.take(4).drop(1)
    cups = listOf(active) + cups.drop(4)

    var next = active
    do {
      next--
      if (next <= 0) {
        next = cups.size + 3
      }
    } while (next in three)
    cups = three + moveToEnd(cups, next)
    cups = moveToEnd(cups, active)
  }

  println(moveToEnd(cups, 1).dropLast(1).joinToString(""))
}
