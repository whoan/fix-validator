# FIX validator

This is a simple FIX scheme/dictionary validator which relies on [QuickFIX](https://github.com/quickfix/quickfix).

## Compile

```bash
mkdir build && cd build
cmake .. && make -j$(nproc)
```

## Run

```bash
fix-validator < your_dictionary.xml
```

## To-Do

- Create Dockerfile
- Publish docker image
- Create service

## License

[MIT](https://github.com/whoan/fix-validator/blob/master/LICENSE)
