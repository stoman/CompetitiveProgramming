import java.util.*

private fun <T> List<T>.mode(tieBreaker: Comparator<T>): T? {
  val comparator = compareBy<Map.Entry<T, List<T>>> { it.value.size }.thenBy(tieBreaker, { it.key })
  return groupBy { it }.maxOfWithOrNull(comparator, { it })?.key
}

private fun filter(bits: List<List<Boolean>>, selector: (List<Boolean>) -> Boolean, index: Int = 0): List<Boolean> {
  val bitCriterion = selector(bits.map { it[index] })
  val selection = bits.filter { it[index] == bitCriterion }
  return if (selection.size == 1) selection[0] else filter(selection, selector, index + 1)
}

private fun List<Boolean>.binary(): Int = reversed().mapIndexed { i, b -> if (b) 1 shl i else 0 }.sum()

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val report = buildList {
    while (s.hasNext()) {
      add(s.next().map { it == '1' })
    }
  }
  val oxygenGeneratorRating = filter(report, { it.mode(naturalOrder())!! }).binary()
  val co2ScrubberRating = filter(report, { !it.mode(naturalOrder())!! }).binary()
  println(oxygenGeneratorRating * co2ScrubberRating)
}