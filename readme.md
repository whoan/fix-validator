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

### Use public service

```bash
curl -k -H "Content-Type: application/json" https://fix-validator.whoan.online/ -d"{\"data\": \"$(base64 -w0 your_schema.xml)\"}"
```

### Create a handy command to use public service

```bash
fixv() {
  local schema
  schema="${1:?PLease provide a FIX schema file to validate}"
  curl -k -H "Content-Type: application/json" https://fix-validator.whoan.online/ -d"{\"data\": \"$(base64 -w0 "$schema")\"}"
}
```

## License

[MIT](https://github.com/whoan/fix-validator/blob/master/LICENSE)
