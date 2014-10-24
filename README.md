# mafintosh/base

Base image based on ubuntu that contains basic builds tools and a spawn helper

```
docker pull mafintosh/base
```

In addition to basic build tools (build-essential, git etc) this contains a program
called `spawn` written in c for minimum memory footprint.
The only thing this program does is spawn another a child process with the arguments you pass to it. This way you avoid being PID=1 (which otherwise might result in some issues)

## Example usage

Just use the `FROM` stanza and add `spawn` to your `ENTRYPOINT` if you want to use thats

```
FROM mafintosh/base
ENTRYPOINT ["spawn", "my-app"]
```

## License

MIT