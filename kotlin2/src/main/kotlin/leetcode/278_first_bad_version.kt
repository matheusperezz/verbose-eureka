package leetcode

open class VersionControl {
    // Suponha que esta classe seja fornecida como parte do problema,
    // com o método isBadVersion implementado na API.
    fun isBadVersion(version: Int): Boolean {
        // Implementação fictícia do método isBadVersion.
        // Substitua isso com a implementação real fornecida pelo problema.
        return false
    }
}

class Solution278: VersionControl() {
    fun firstBadVersion(n: Int) : Int {
        var left = 1
        var right = n

        while (left < right) {
            val mid = left + (right - left) / 2

            if (isBadVersion(mid)) {
                right = mid
            } else {
                left = mid + 1
            }
        }

        return left
    }
}

fun main(){

}