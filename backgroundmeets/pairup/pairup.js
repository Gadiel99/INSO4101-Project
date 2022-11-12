var scheduledButton = document.getElementById("viewScheduledMeets")
var pendingButton = document.getElementById("viewPendingMeets")

var scheduledView = document.getElementById("viewingScheduled")

var pendingView = document.getElementById("viewingPending")

scheduledButton.addEventListener("click", function (event) {

    scheduledButton.style.backgroundColor = "#4EEF8A"

    pendingButton.style.backgroundColor = "#11823B"

    scheduledView.style.opacity = 1

    pendingView.style.opacity = 0
})

pendingButton.addEventListener("click", function (event) {

    scheduledButton.style.backgroundColor = "#11823B"

    pendingButton.style.backgroundColor = "#4EEF8A"

    scheduledView.style.opacity = 0

    pendingView.style.opacity = 1

})