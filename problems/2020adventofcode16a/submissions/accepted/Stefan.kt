import java.util.*

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\s\syour ticket:\s|\s\snearby tickets:\s""")

  // Read ranges.
  val sRanges = Scanner(s.next()).useDelimiter(""":\s|\sor\s|-|\n""")
  val ranges = mutableMapOf<String, Set<IntRange>>()
  while (sRanges.hasNext()) {
    val name = sRanges.next()
    ranges[name] = setOf(sRanges.nextInt()..sRanges.nextInt(), sRanges.nextInt()..sRanges.nextInt())
  }

  // Read tickets
  val tickets = mutableListOf<List<Int>>()
  repeat(2) {
    val sTickets = Scanner(s.next())
    while (sTickets.hasNext()) {
      tickets.add(sTickets.next().split(",").map { it.toInt() })
    }
  }

  println(tickets.flatten().filter { i -> ranges.values.flatten().none { i in it } }.sum())
}
