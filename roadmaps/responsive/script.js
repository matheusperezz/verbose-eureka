const modal = document.getElementById("myModal")

document.addEventListener("DOMContentLoaded", function() {
    const carList = document.getElementById("car-list")
    const carDescription = document.getElementById("car-description")

    carList.addEventListener("click", function(event) {
        if (event.target.tagName === "IMG"){
            const description = event.target.getAttribute("data-description")
            carDescription.textContent = description
        }
    })
})

function openModal(){
    modal.style.display = "block"
}

function closeModal(){
    modal.style.display = "none"
}