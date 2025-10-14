# 📦 C++ Dev Container con Debug en VS Code

Este proyecto contiene un entorno de desarrollo para **C++** usando **Dev Containers** en VS Code, con soporte para compilación, ejecución y depuración (local y remota con `gdbserver`).  

---

## 🔹 Requisitos previos

1. [Docker](https://docs.docker.com/get-docker/) instalado y corriendo.  
2. [Visual Studio Code](https://code.visualstudio.com/) instalado.  
3. Extensiones recomendadas:  
   - [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)  
   - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)  

---

## 🔹 Apertura del Dev Container

1. Clona este repositorio:  

    ```bash
    git clone https://github.com/usuario/cpp-docker.git
    cd cpp-docker
    ```

2. Abre la carpeta en VS Code:

    ```bash
    code .
    ```

3. VS Code detectará el archivo `.devcontainer/devcontainer.json`.
- Haz clic en **Reopen in Container**. Si no aparece pulsa **Ctrl+Shift+P** y luego buscas la opción **Reopen in Container**.
- Se construirá la imagen y abrirá un entorno con `g++`, `make`, `gdb`, `gdbserver`, `curl` y `nlohmann/json`.


## 🔹 Compilación y ejecución

Dentro del Dev Container:

```bash
make           # Compila con símbolos de depuración
make run       # Ejecuta el binario
make clean     # Limpia binarios
```

El binario generado es `main`.


## 🔹 Debugging en VS Code
El archivo `.vscode/launch.json` ya incluye la configuración de depuración:
- Debug (gdbserver :2345) → Permite depuración remota con `gdbserver`.
1. En una terminal del contenedor, compila y lanza `gdbserver`:
```bash
make gdbserver
```
Esto mostrará algo como:
```bash
Listening on port 2345
Waiting for gdb connection...
```
2. En VS Code pulsa **F5**. Se conectará al puerto *2345* y podrás depurar de forma remota.

## 🔹 Google Testing
Se debe modificar el archivo `tests/test_main.cpp` con los test que requeridos.

Dentro del Dev Container:

```bash
make google-test       # Ejecuta los test con la librería gtest de google
```

El binario generado es `test_runner`.