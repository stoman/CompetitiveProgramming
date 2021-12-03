import java.util.*

private fun <T>List<T>.mode(): T? = groupBy { it }.maxByOrNull { it.value.size }?.key

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val report = buildList {
    while (s.hasNext()) {
      add(s.next().map { it == '1' })
    }
  }
  val bits = report.first().indices.map { i -> report.map { it[i] } }.reversed()
  val modes = bits.map { it.mode() }
  val gamma = modes.mapIndexed { i, b -> if(b == true) 1 shl i else 0 }.sum()
  val epsilon = modes.mapIndexed { i, b -> if(b == false) 1 shl i else 0 }.sum()
  println(gamma * epsilon)
}
