import java.util.Scanner

fun main() {
    val s = Scanner(System.`in`)

    val input = mutableSetOf<Int>()
    while(s.hasNext()) {
        input.add(s.nextInt())
    }

    for(i in input) {
        val j = 2020 - i
        if(j in input) {
            println(i*j)
            return
        }
    }
}
