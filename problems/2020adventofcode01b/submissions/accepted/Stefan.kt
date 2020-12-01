import java.util.Scanner

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  var input = mutableSetOf<Int>()
  while (s.hasNext()) {
    input.add(s.nextInt())
  }

  for (i in input) {
    for(j in input) {
      if(i > j) {
        val k = 2020 - i - j
        if (k in input) {
          println(i * j * k)
          return
        }
      }
    }
  }
}
