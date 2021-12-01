import java.util.Scanner

fun main(args: Array<String>) {
    val s = Scanner(System.`in`)

    val history = mutableListOf<Int>()
    var increases = 0
    while(s.hasNext()) {
        history.add(s.nextInt())
        if(history.size >= 4 && history.last() > history[history.size - 4]) {
            increases++
        }
    }

    println(increases)
}
