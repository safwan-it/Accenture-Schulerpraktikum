// "Mehr anzeigen"-Buttons auf den Cards
const buttons = document.querySelectorAll(".mehr-button");

buttons.forEach(function (button) {
    button.addEventListener("click", function () {
        const text = button.nextElementSibling;
        text.classList.toggle("sichtbar");

        if (text.classList.contains("sichtbar")) {
            button.textContent = "Weniger anzeigen";
        } else {
            button.textContent = "Mehr anzeigen";
        }
    });
});