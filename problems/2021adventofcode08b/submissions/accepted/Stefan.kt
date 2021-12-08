import java.util.*

private fun <T> Collection<T>.only(): T {
  require(size == 1)
  return first()
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\n")
  var ret = 0
  while (s.hasNext()) {
    val line = s.next().split(" | ")
    val input = line[0].split(" ")
    val output = line[1].split(" ")
    val inputBySize = input.map { it.toSet() }.groupBy { it.size }

    // Reconstruct which segment belongs to which input character.
    // Segments in this list are ordered top to bottom, left to right.
    val segments = MutableList(7) { ' ' }
    segments[0] = ((inputBySize[3]!!.only()) - inputBySize[2]!!.only()).only()
    val cf = inputBySize[2]!!.only().sortedBy { t -> input.count { it.toSet().contains(t) } }
    segments[2] = cf[0]
    segments[5] = cf[1]
    val bd = (inputBySize[4]!!.only() - cf).sortedBy { t -> input.count { it.toSet().contains(t) } }
    segments[1] = bd[0]
    segments[3] = bd[1]
    val eg = (inputBySize[7]!!.only() - segments).sortedBy { t -> input.count { it.toSet().contains(t) } }
    segments[4] = eg[0]
    segments[6] = eg[1]

    // Reconstruct numbers and map the output back.
    val numbers = mapOf(
      setOf(segments[0], segments[1], segments[2], segments[4], segments[5], segments[6]) to 0,
      setOf(segments[2], segments[5]) to 1,
      setOf(segments[0], segments[2], segments[3], segments[4], segments[6]) to 2,
      setOf(segments[0], segments[2], segments[3], segments[5], segments[6]) to 3,
      setOf(segments[1], segments[2], segments[3], segments[5]) to 4,
      setOf(segments[0], segments[1], segments[3], segments[5], segments[6]) to 5,
      setOf(segments[0], segments[1], segments[3], segments[4], segments[5], segments[6]) to 6,
      setOf(segments[0], segments[2], segments[5]) to 7,
      setOf(segments[0], segments[1], segments[2], segments[3], segments[4], segments[5], segments[6]) to 8,
      setOf(segments[0], segments[1], segments[2], segments[3], segments[5], segments[6]) to 9
    )
    ret += output.map { numbers[it.toSet()] }.joinToString("").toInt()
  }
  println(ret)
}
