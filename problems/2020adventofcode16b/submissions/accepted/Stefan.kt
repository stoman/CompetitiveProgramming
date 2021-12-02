import java.math.BigInteger
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
  val myTicket: List<Int> = s.next().split(",").map { it.toInt() }
  val sTickets = Scanner(s.next())
  val tickets = mutableListOf<List<Int>>()
  while (sTickets.hasNext()) {
    tickets.add(sTickets.next().split(",").map { it.toInt() })
  }

  // Determine meaning of fields.
  val validTickets = tickets.filter { ticket -> ticket.none { i -> ranges.values.flatten().none { i in it } } }
  var possible = mutableMapOf<Int, Set<String>>()
  for (i in myTicket.indices) {
    possible[i] =
      ranges.filter { entry -> validTickets.map { it[i] }.all { nr -> entry.value.any { nr in it } } }.map { it.key }
        .toSet()
  }
  val mapping = mutableMapOf<String, Int>()
  while (true) {
    val next: Int = possible.keys.firstOrNull { possible[it]!!.size == 1 } ?: break
    val name: String = possible[next]!!.first()
    mapping[name] = next
    possible = possible.mapValues { it.value.filter { n -> n != name }.toSet() }.toMutableMap()
  }

  println(mapping.filterKeys { it.startsWith("departure") }.map { myTicket[it.value].toBigInteger() }
    .reduce(BigInteger::times))
}
