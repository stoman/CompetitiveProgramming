import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\s->\s|\n\n|\n""")
  val input = s.next()
  var polymers = (0 until input.length - 1).map { input.slice(it..(it + 1)) }.groupBy { it }.mapValues { it.value.size }
  val rules = buildMap<String, String> { while (s.hasNext()) { put(s.next(), s.next()) } }

  repeat(10) {
    val newPolymers = mutableMapOf<String, Int>()
    for ((str, count) in polymers) {
      val n = rules[str]!!
      newPolymers[str[0] + n] = newPolymers.getOrDefault(str[0] + n, 0) + count
      newPolymers[n + str[1]] = newPolymers.getOrDefault(n + str[1], 0) + count
    }
    polymers = newPolymers
  }

  val counts = mutableMapOf(input.last() to 1)
  for ((str, count) in polymers) {
    counts[str[0]] = counts.getOrDefault(str[0], 0) + count
  }
  println(counts.maxOf { it.value } - counts.minOf { it.value })
}
