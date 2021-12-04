import java.util.*

private fun <T> List<List<T>>.transpose(): List<List<T>> {
  if (isEmpty()) {
    return listOf()
  }
  require(this.map { it.size }.toSet().size == 1) { "Matrix needs to have a square shape to be transposed" }
  val ret = List(first().size) { mutableListOf<T>() }
  for (list in this) {
    for (i in list.indices) {
      ret[i].add(list[i])
    }
  }
  return ret
}

data class Board(val numbers: List<List<Int>>) {
  fun isCompleted(draw: List<Int>): Boolean =
    numbers.any { draw.containsAll(it) } || numbers.transpose().any { draw.containsAll(it) }
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val draw = buildList {
    val ss = Scanner(s.next()).useDelimiter(",")
    while (ss.hasNext()) {
      add(ss.nextInt())
    }
  }
  val boards = mutableListOf<Board>()
  while (s.hasNext()) {
    val numbers = List(5) { mutableListOf<Int>() }
    repeat(5) { row ->
      repeat(5) { numbers[row].add(s.nextInt()) }
    }
    boards.add(Board(numbers))
  }

  for (drawIndex in draw.indices) {
    val allDraws = draw.take(drawIndex + 1)
    if (boards.size == 1 && boards.first().isCompleted(allDraws)) {
      println(allDraws.last() * boards.first().numbers.flatten().filterNot { it in allDraws }.sum())
      return
    }
    boards.removeIf { it.isCompleted(allDraws) }
  }
}
