import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val (nString, game) = br.readLine().split(' ')

    val n = nString.toInt()

    val list = ArrayList<String>()
    for(i in 0 until n)
        list.add(br.readLine())

    val nameSet = list.toSet()

    when(game) {
        "Y" -> {
            println(nameSet.size)
        }
        "F" -> {
            println(nameSet.size / 2)
        }
        "O" -> {
            println(nameSet.size / 3)
        }
    }
}
