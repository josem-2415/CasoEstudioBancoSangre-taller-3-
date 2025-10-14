#include "ValidacionTelefonos.h"
#include <iostream>
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <json/json.h>

// Función auxiliar: guarda la respuesta HTTP en un std::string 
static size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp) {
    auto& output = *static_cast<std::string*>(userp);
    output.append(contents, size * nmemb);
    return size * nmemb;
}

bool PhoneValidator::validate(long long phone) {
    const std::string apiKey = "3536cbb969e837409895c834d4d30931";  //Llave API
    const std::string url =
        "http://apilayer.net/api/validate?access_key=" + apiKey +
        "&number=" + std::to_string(phone) + "&country_code=CO";

    std::string responseBuffer;

    // --- Gestión automática del recurso CURL ---
    // Usamos un objeto que se destruye solo 
    CURL* curlHandle = curl_easy_init();
    if (!curlHandle) {
        std::cerr << "Error: No se pudo inicializar CURL.\n";
        return false;
    }

    curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &responseBuffer);

    CURLcode result = curl_easy_perform(curlHandle);
    curl_easy_cleanup(curlHandle);

    if (result != CURLE_OK) {
        std::cerr << "Error al conectarse a NumVerify: "
                  << curl_easy_strerror(result) << "\n";
        return false;
    }

    Json::Value jsonData;
    Json::CharReaderBuilder builder;
    std::istringstream iss(responseBuffer);
    std::string errs;

    // Análisis JSON 
    if (!Json::parseFromStream(builder, iss, &jsonData, &errs)) {
        std::cerr << "Error al analizar la respuesta JSON: " << errs << "\n";
        return false;
    }

    if (jsonData.isMember("valid") && jsonData["valid"].asBool()) {
        std::cout << "Número válido según NumVerify.\n";
        return true;
    }

    std::cout << "Número inválido según NumVerify.\n";
    return false;
}
