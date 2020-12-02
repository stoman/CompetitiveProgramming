import java.util.Scanner

fun main(args: Array<String>) {
    val s = Scanner(System.`in`).useDelimiter("-|\\s|:\\s")

    var r = 0
    while(s.hasNext()) {
        val min = s.nextInt()
        val max = s.nextInt()
        val char = s.next()[0]
        val password = s.next()
        val matches = password.toList().count { it == char }
        if(min <= matches && matches <= max) {
            r++
        }
    }
    println(r)
}
