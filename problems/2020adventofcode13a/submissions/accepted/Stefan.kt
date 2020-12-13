import java.util.*

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\\s|,")
  val arrival = s.nextInt()
  val busses = mutableListOf<Int>()
  while (s.hasNext()) {
    val bus = s.next()
    if (bus != "x") {
      busses.add(bus.toInt())
    }
  }
  val waitTime = {bus: Int -> bus - (arrival % bus)}
  val myBus = busses.minBy(waitTime) ?: return
  println(myBus * waitTime(myBus))
}
