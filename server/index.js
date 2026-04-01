import express from "express";
import axios from "axios";
import path from "path";
import { fileURLToPath } from "url";

const app = express();
const PORT = 3000;
const ESP32_IP = "http://192.168.4.1";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));
app.use(express.static(path.join(__dirname, "public")));

app.get("/", (req, res) => {
    res.render("index");
});

app.get("/on", async (req, res) => {
    try {
        await axios.get(`${ESP32_IP}/on`);
    } catch (error) {
        console.error("Failed to turn ON the ESP32 LED:", error.message);
    }

    res.redirect("/");
});

app.get("/off", async (req, res) => {
    try {
        await axios.get(`${ESP32_IP}/off`);
    } catch (error) {
        console.error("Failed to turn OFF the ESP32 LED:", error.message);
    }

    res.redirect("/");
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
