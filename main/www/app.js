/*
 * Phase B: there is no backend endpoint yet. This file only proves that the
 * browser fetched it from the server and executed it. Phase C will replace the
 * placeholder logic with a fetch() call to /api/sensor.
 */
document.addEventListener("DOMContentLoaded", function () {
  var status = document.getElementById("status");
  status.textContent = "JavaScript loaded at " + new Date().toLocaleTimeString();
  status.classList.add("ok");
});