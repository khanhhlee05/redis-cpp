# Caching Proxy (C++)

A learning project for building a CLI-based HTTP caching proxy in C++.

Current progress:
- CLI argument parsing (`--port`, `--origin`, `--clear-cache`)
- Basic HTTP server with Boost.Beast
- Fixed response flow (`Hello, World!`)

## Project Structure

```text
redis-cpp/
  include/
    server.h
    utilities.h
  src/
    main.cpp
    server.cpp
    utilities.cpp
  Makefile
  compile_commands.json
  .clangd
```

## Requirements

- macOS/Linux
- `clang++` with C++17 support
- Boost headers (Homebrew path currently used in build flags)

Install Boost on macOS:

```bash
brew install boost
```

## Build

From project root:

```bash
make build
```

This produces the executable:
- `./caching-proxy`

## Run

Run server mode:

```bash
./caching-proxy --port 3000 --origin http://dummyjson.com
```

Or use Makefile shortcut:

```bash
make run
```

## Test

In another terminal:

```bash
curl -i http://localhost:3000/products
```

Current expected behavior:
- Returns a fixed HTTP `200` response with body `Hello, World!`

## CLI Usage

```bash
./caching-proxy --port <port> --origin <url>
./caching-proxy --clear-cache
```

## Makefile Commands

- `make` or `make build` - compile project
- `make run` - build and run with default args
- `make test` - send test request to local server
- `make clean` - remove binary

## Next Milestones

1. Forward incoming requests to the origin server
2. Return origin response headers/body/status
3. Add in-memory cache for GET requests
4. Add `X-Cache: MISS/HIT` response header
5. Add cache invalidation strategy
